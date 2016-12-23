#include "hooks.h"

void Hooks::FrameStageNotify(void* thisptr, ClientFrameStage_t stage)
{
	CustomGlow::FrameStageNotify(stage);
	SkinChanger::FrameStageNotify(stage);
	Noflash::FrameStageNotify(stage);
	View::FrameStageNotify(stage);
	Resolver::FrameStageNotify(stage);

#ifdef EXPERIMENTAL_SETTINGS
	NoSky::FrameStageNotify(stage);
	ASUSWalls::FrameStageNotify(stage);
#endif

	client_vmt->GetOriginalMethod<FrameStageNotifyFn>(36)(thisptr, stage);

	Resolver::PostFrameStageNotify(stage);
	View::PostFrameStageNotify(stage);
}