#pragma once

#include "../Cheat.h"

class CClantagChanger
{
public:
	struct Frame
	{
		int time;
		std::string text;

		Frame(std::string text, int time)
		{
			this->text = text;
			this->time = time;
		}
	};

	enum AnimationLoopType
	{
		ANIM_LOOP,
		ANIM_LOOP_BACK
	};

	struct Animation
	{
		std::string name;
		unsigned int currentFrame;
		std::vector<Frame> frames;
		AnimationLoopType loopType;

		Animation(std::string name, std::vector<Frame> frames, AnimationLoopType loopType)
		{
			currentFrame = 0;
			this->name = name;
			this->frames = frames;
			this->loopType = loopType;
		}

		Frame GetCurrentFrame()
		{
			return frames[currentFrame];
		}

		void NextFrame()
		{
			currentFrame++;

			if (currentFrame >= frames.size())
				currentFrame = 0;
		}
	};

	Animation Marquee(std::string name, std::string text, int width = 15);
	//Animation Words(std::string name, std::wstring text);
	Animation Letters(std::string name, std::string text);

	std::vector<Animation> animations = {
		Marquee("BADSTER", "BADSTER.XYZ - BADSTER.XYZ - OWNS ME AND ALL!"),
		//Words("BADSTER", "BADSTER.XYZ - BADSTER.XYZ - OWNS ME AND ALL!"),
		Letters("BADSTER", "BADSTER.XYZ - BADSTER.XYZ - OWNS ME AND ALL!")
	};
	Animation* animation = &animations[0];

	void UpdateClanTagCallback();
	void BeginFrame();

};
