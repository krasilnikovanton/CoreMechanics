

using UnrealBuildTool;
using System.Collections.Generic;

public class ShopTarget : TargetRules
{
	public ShopTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Shop" } );
	}
}
