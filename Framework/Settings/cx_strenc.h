#pragma once

#include "cx_pcg32.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>

namespace cx
{
	namespace err
	{
		namespace
		{
			const char* strenc_runtime_error;
		}
	}

	namespace detail
	{
		template <uint64_t S>
		constexpr char encrypt_at( const char* s, size_t idx )
		{
			return s[ idx ] ^
				static_cast<char>( pcg::pcg32_output( pcg::pcg32_advance( S, idx + 1 ) ) >> 24 );
		}

		template <size_t N>
		struct char_array
		{
			char data[ N ];
		};

		inline std::string decrypt( uint64_t S, const char* s, size_t n )
		{
			std::string ret;
			ret.reserve( n );
			for( size_t i = 0; i < n; ++i )
			{
				S = pcg::pcg32_advance( S );
				ret.push_back( s[ i ] ^ static_cast<char>( pcg::pcg32_output( S ) >> 24 ) );
			}
			return ret;
		}

		template <uint64_t S, size_t ...Is>
		constexpr char_array<sizeof...( Is )> encrypt( const char *s, std::index_sequence<Is...> )
		{
			return{ { encrypt_at<S>( s, Is )... } };
		}
	}

	template <uint64_t S, size_t N>
	class encrypted_string
	{
	public:
		constexpr encrypted_string( const char( &a )[ N ] )
			: m_enc( detail::encrypt<S>( a, std::make_index_sequence<N - 1>() ) )
		{}

		constexpr size_t size() const { return N - 1; }

		operator std::string() const
		{
			return detail::decrypt( S, m_enc.data, N - 1 );
		}

	private:
		const detail::char_array<N - 1> m_enc;
	};

	template <uint64_t S, size_t N>
	constexpr encrypted_string<S, N> make_encrypted_string( const char( &s )[ N ] )
	{
		return true ? encrypted_string<S, N>( s ) :
			throw err::strenc_runtime_error;
	}
}

#define CX_ENCSTR_RNGSEED uint64_t{cx::fnv1(__FILE__ __DATE__ __TIME__) + __LINE__}
#define cx_make_encrypted_string cx::make_encrypted_string<CX_ENCSTR_RNGSEED>

#ifdef NDEBUG
#define strenc( s ) std::string( cx_make_encrypted_string( s ) )
#define charenc( s ) strenc( s ).c_str()
#define wstrenc( s ) std::wstring( strenc( s ).begin(), strenc( s ).end() )
#define wcharenc( s ) wstrenc( s ).c_str()
#else
#define strenc( s ) ( s )
#define charenc( s ) ( s )
#define wstrenc( s ) ( s )
#define wcharenc( s ) ( s )
#endif

