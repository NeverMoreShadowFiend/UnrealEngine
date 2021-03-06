// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UnrealEd.h"

// FPreviewScene derived helpers for rendering
#include "ThumbnailHelpers.h"
#include "EngineModule.h"
#include "RendererInterface.h"
#include "Engine/StaticMesh.h"
#include "FoliageType_ISMThumbnailRenderer.h"
#include "FoliageType_InstancedStaticMesh.h"

bool UFoliageType_ISMThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UFoliageType_InstancedStaticMesh* FoliageType = Cast<UFoliageType_InstancedStaticMesh>(Object);
	return FoliageType && FoliageType->GetStaticMesh();
}

void UFoliageType_ISMThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas)
{
	UFoliageType_InstancedStaticMesh* FoliageType = Cast<UFoliageType_InstancedStaticMesh>(Object);
	if (FoliageType && FoliageType->GetStaticMesh())
	{
		if (ThumbnailScene == nullptr)
		{
			ThumbnailScene = new FStaticMeshThumbnailScene();
		}

		ThumbnailScene->SetStaticMesh(FoliageType->GetStaticMesh());
		ThumbnailScene->SetOverrideMaterials(FoliageType->OverrideMaterials);
		ThumbnailScene->GetScene()->UpdateSpeedTreeWind(0.0);

		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(RenderTarget, ThumbnailScene->GetScene(), FEngineShowFlags(ESFIM_Game))
			.SetWorldTimes(FApp::GetCurrentTime() - GStartTime, FApp::GetDeltaTime(), FApp::GetCurrentTime() - GStartTime));

		ViewFamily.EngineShowFlags.DisableAdvancedFeatures();
		ViewFamily.EngineShowFlags.MotionBlur = 0;
		ViewFamily.EngineShowFlags.LOD = 0;

		ThumbnailScene->GetView(&ViewFamily, X, Y, Width, Height);
		GetRendererModule().BeginRenderingViewFamily(Canvas, &ViewFamily);
		ThumbnailScene->SetStaticMesh(nullptr);
		ThumbnailScene->SetOverrideMaterials(TArray<class UMaterialInterface*>());
	}
}

void UFoliageType_ISMThumbnailRenderer::BeginDestroy()
{
	if (ThumbnailScene != nullptr)
	{
		delete ThumbnailScene;
		ThumbnailScene = nullptr;
	}

	Super::BeginDestroy();
}
