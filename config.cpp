class CfgPatches
{
	class FalconSkills
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data", "JM_CF_Scripts"};
	};
}

class CfgMods
{
	class FalconSkills
	{
	    dir = FalconSkills
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = FalconSkills
	    credits = "";
	    author = "";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = {"World", "Mission" };

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[]=
				{
					"FalconSkills/Defines",
					"FalconSkills/4_World"
				};
			};

			class missionScriptModule
			{
				value = "";
				files[]=
				{
					"FalconSkills/Defines"
				};
			};
		};
	};
};

class CfgVehicles
{
	class Paper;
	class SkillBook: Paper
	{
		scope=2;
		displayName="Skill Book";
		descriptionShort="A skill book";
		model="\FalconSkills\skillbook\testbook.p3d";
		rotationFlags=0;
		weight=500;
		itemSize[]={3,2};
		fragility=0.00000005;
	};

	//Mining
	class MiningGoldBook: SkillBook
	{
		displayName = "Mining Gold Skill Book";
		descriptionShort = "";
	};
	//Mechanic
	class MechanicBookBeginner: SkillBook
	{
		displayName = "Mechanic Skill Book (Beginner)";
		descriptionShort = "Mechanic skill book Beginner";
	};
	class MechanicBookIntermediate: SkillBook
	{
		displayName = "Mechanic Skill Book (Intermediate)";
		descriptionShort = "Mechanic skill book Intermediate";
	};
	class MechanicBookAdvanced: SkillBook
	{
		displayName = "Mechanic Skill Book (Advanced)";
		descriptionShort = "Mechanic skill book Advanced";
	};
	//Medical
	class MedicalBookBeginner: SkillBook
	{
		displayName = "Medical Skill Book (Beginner)";
		descriptionShort = "Medical skill book Beginner";
	};
	class MedicalBookIntermediate: SkillBook
	{
		displayName = "Medical Skill Book (Intermediate)";
		descriptionShort = "Medical skill book Intermediate";
	};
	class MedicalBookAdvanced: SkillBook
	{
		displayName = "Medical Skill Book (Advanced)";
		descriptionShort = "Medical skill book Advanced";
	};

	//Building
	class BuildingBookBeginner: SkillBook
	{
		displayName = "Building Skill Book (Beginner)";
		descriptionShort = "Building skill book Beginner";
	};
	class BuildingBookIntermediate: SkillBook
	{
		displayName = "Building Skill Book (Intermediate)";
		descriptionShort = "Building skill book Intermediate";
	};
	class BuildingBookAdvanced: SkillBook
	{
		displayName = "Building Skill Book (Advanced)";
		descriptionShort = "Building skill book Advanced";
	};

};
