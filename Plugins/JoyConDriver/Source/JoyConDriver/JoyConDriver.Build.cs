// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JoyConDriver : ModuleRules {
	public JoyConDriver(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        bEnableUndefinedIdentifierWarnings = false;

        PublicIncludePaths.AddRange(new string[] {

        });

        PrivateIncludePaths.AddRange(new string[] {

        });

        PublicDependencyModuleNames.AddRange(new string[] {

        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "ApplicationCore",
            "Engine",
            "InputCore",
            "HeadMountedDisplay"
        });

        PrivateIncludePathModuleNames.AddRange(new string[] {
            "InputDevice",
            "HeadMountedDisplay",
            "ImageWrapper"
        });

        DynamicallyLoadedModuleNames.AddRange(new string[] {

        });
	}
}
