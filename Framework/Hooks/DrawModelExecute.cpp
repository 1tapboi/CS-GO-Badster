#include "../Cheat.h"
#include "../XOR.h"

DrawModelExecuteFn oDrawModelExecute;

void ForceMaterial( IMaterial* material, Color color )
{
	if( material != NULL )
	{
		I::RenderView->SetColorModulation( color.Base() );
		I::ModelRender->ForcedMaterialOverride( material );
	}
}


void __stdcall Hooks::DrawModelExecute(void* context, void* state, const ModelRenderInfo_t& info, matrix3x4_t* pCustomBoneToWorld)
{
	H::ModelRender->UnHook();

	if (I::Engine->IsInGame() && G::LocalPlayer && !I::Engine->IsTakingScreenshot() && I::Engine->IsConnected())
	{
		if (info.pModel)
		{
			std::string modelName = I::ModelInfo->GetModelName(info.pModel);
			const char* ModelName = I::ModelInfo->GetModelName((model_t*)info.pModel);

			if (modelName.find(/*arms*/XorStr<0x69, 5, 0xE1CCA208>("\x08\x18\x06\x1F" + 0xE1CCA208).s) != std::string::npos && (Vars.Visuals.Chams.Hands))
			{
				if (Vars.Visuals.Chams.RainbowHands)
				{
					IMaterial* Hands = I::MaterialSystem->FindMaterial(modelName.c_str(), charenc(TEXTURE_GROUP_MODEL));
					Hands->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
					static float rainbow;
					rainbow += (Vars.Visuals.Chams.RainbowTime / 100000);
					if (rainbow > 1.f) rainbow = 0.f;
					Color render_color_visible = Color::FromHSB(rainbow, 1.f, 1.f);
					if (Vars.Visuals.Chams.Mode == 0)
						hidden_flat->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
					else
						hidden_tex->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);

					ForceMaterial(Vars.Visuals.Chams.Mode == 0 ? visible_flat : visible_tex, render_color_visible);
					I::ModelRender->DrawModelExecute(context, state, info, pCustomBoneToWorld);
				}
				else
				{
					IMaterial* Hands = I::MaterialSystem->FindMaterial(modelName.c_str(), charenc(TEXTURE_GROUP_MODEL));
					if (Vars.Visuals.Chams.WireframeHands) {
						Hands->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, true);
						I::ModelRender->ForcedMaterialOverride(Hands);
					}
					else
					{
						IMaterial* Hands = I::MaterialSystem->FindMaterial(modelName.c_str(), charenc(TEXTURE_GROUP_MODEL));
						if (Vars.Visuals.Chams.WireframeHandsZ) {
							Hands->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, true);
							I::ModelRender->ForcedMaterialOverride(Hands);
						}

						Color render_color_visible;
						Color render_color_hidden;


						if (Vars.Visuals.colorsV == 0 && Vars.Visuals.colorsNV == 0)
						{
							render_color_hidden = G::LocalPlayer->GetTeam() ? Color(200, 5, 5) : Color(200, 5, 5);
							render_color_visible = G::LocalPlayer->GetTeam() ? Color(5, 200, 5) : Color(5, 200, 5);
						}
						else
						{
							render_color_hidden = G::LocalPlayer->GetTeam() ? Color(Vars.Visuals.colNV.r, Vars.Visuals.colNV.g, Vars.Visuals.colNV.b) : Color(Vars.Visuals.colNV.r, Vars.Visuals.colNV.g, Vars.Visuals.colNV.b);
							render_color_visible = G::LocalPlayer->GetTeam() ? Color(Vars.Visuals.colV.r, Vars.Visuals.colV.g, Vars.Visuals.colV.b) : Color(Vars.Visuals.colV.r, Vars.Visuals.colV.g, Vars.Visuals.colV.b);
						}

						if (Vars.Visuals.Chams.Hands)
						{
							if (Vars.Visuals.Chams.XQZ)
							{
								ForceMaterial(Vars.Visuals.Chams.Mode == 0 ? hidden_flat : hidden_tex, render_color_hidden);
								I::ModelRender->DrawModelExecute(context, state, info, pCustomBoneToWorld);
							}

							if (Vars.Visuals.Chams.Mode == 0)
								hidden_flat->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
							else
								hidden_tex->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
						}
						ForceMaterial(Vars.Visuals.Chams.Mode == 0 ? visible_flat : visible_tex, render_color_visible);
						I::ModelRender->DrawModelExecute(context, state, info, pCustomBoneToWorld);
					}
				}
			}

				if (modelName.find(strenc("models/player")) != std::string::npos && Vars.Visuals.Chams.Enabled)
				{
					CBaseEntity* Entity = I::ClientEntList->GetClientEntity(info.entity_index);
					player_info_t pInfo;
					I::Engine->GetPlayerInfo(info.entity_index, &pInfo);
					if (strcmp(pInfo.guid, "STEAM_ID") != 0 && strcmp(pInfo.guid, "STEAM_ID") != 0)
					{
						CBaseEntity* pModelEntity = (CBaseEntity*)I::ClientEntList->GetClientEntity(info.entity_index);
						if (pModelEntity && pModelEntity->GetAlive() && !pModelEntity->GetDormant() && Entity->GetTeam() != G::LocalPlayer->GetTeam())
						{
							Color render_color_visible;
							Color render_color_hidden;


							render_color_hidden = pModelEntity->GetTeam() == 2 ? Color(Vars.Visuals.colNV.r, Vars.Visuals.colNV.g, Vars.Visuals.colNV.b) : Color(Vars.Visuals.colNV.r, Vars.Visuals.colNV.g, Vars.Visuals.colNV.b);


							render_color_visible = G::LocalPlayer->GetTeam() ? Color(Vars.Visuals.colV.r, Vars.Visuals.colV.g, Vars.Visuals.colV.b) : Color(Vars.Visuals.colV.r, Vars.Visuals.colV.g, Vars.Visuals.colV.b);

							if (Vars.Visuals.Chams.XQZ)
							{
								ForceMaterial(Vars.Visuals.Chams.Mode == 0 ? hidden_flat : hidden_tex, render_color_hidden);
								I::ModelRender->DrawModelExecute(context, state, info, pCustomBoneToWorld);

								if (Vars.Visuals.Chams.Mode == 0)
									hidden_flat->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
								else
									hidden_tex->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
							}

							if (Vars.Visuals.Chams.Mode == 0)
								visible_flat->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);
							else
								visible_tex->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);

							ForceMaterial(Vars.Visuals.Chams.Mode == 0 ? visible_flat : visible_tex, render_color_visible);
							I::ModelRender->DrawModelExecute(context, state, info, pCustomBoneToWorld);
						}
					}
				}
				if (modelName.find("weapon") != std::string::npos && Vars.Visuals.RemovalsWeapon)
				{
					if (!(modelName.find("arms") != std::string::npos))
					{
						IMaterial* Weapon = I::MaterialSystem->FindMaterial(modelName.c_str(), (TEXTURE_GROUP_MODEL));
						Weapon->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, true);
						I::ModelRender->ForcedMaterialOverride(Weapon);
					}
				}
				if (modelName.find("arms") != std::string::npos && Vars.Visuals.RemovalsHands)
				{
					IMaterial* Hands = I::MaterialSystem->FindMaterial(modelName.c_str(), (TEXTURE_GROUP_MODEL));
					Hands->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, true);
					I::ModelRender->ForcedMaterialOverride(Hands);
				}
				if (modelName.find(strenc("flash")) != std::string::npos && Vars.Visuals.RemovalsFlash)
				{
					IMaterial* flash = I::MaterialSystem->FindMaterial(charenc("effects\\flashbang"), charenc(TEXTURE_GROUP_CLIENT_EFFECTS));
					IMaterial* flashWhite = I::MaterialSystem->FindMaterial(charenc("effects\\flashbang_white"), charenc(TEXTURE_GROUP_CLIENT_EFFECTS));
					flash->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, true);
					flashWhite->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, true);
					I::ModelRender->ForcedMaterialOverride(flash);
					I::ModelRender->ForcedMaterialOverride(flashWhite);
				}
		}
		I::ModelRender->DrawModelExecute(context, state, info, pCustomBoneToWorld);
		I::ModelRender->ForcedMaterialOverride(NULL);
		H::ModelRender->ReHook();
		}
	}
