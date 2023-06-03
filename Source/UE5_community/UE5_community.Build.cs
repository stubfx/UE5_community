// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5_community : ModuleRules
{
	public UE5_community(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
