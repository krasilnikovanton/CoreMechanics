

using UnrealBuildTool;
using System.Collections.Generic;

public class ShopEditorTarget : TargetRules
{
	public ShopEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Shop" } );
	}
}
