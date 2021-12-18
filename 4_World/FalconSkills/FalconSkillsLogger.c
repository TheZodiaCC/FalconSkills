class FalconSkillsLogger
{	
	const static string playersSkillsPath = SkillsConsts.PLAYERS_SKILLS_DATA_DIR_PATH;
	
	//Checks if player already has a skill in his skill list
	static bool checkIfPlayerHasSkill(array<string> playerSkills, string levelName)
	{			
		for (int i = 0; i < playerSkills.Count(); i++){
			if (playerSkills.Get(i) == levelName)
			{
				return true;
			}
		}
		
		return false;
	}
	
	//Loads player skills from json file
	static array<string> loadPlayerSkillData(string playerID)
	{
		string playerJsonPath = playersSkillsPath + playerID + ".json";
		
		if (FileExist(playerJsonPath))
		{
			array<string> playerSkillsData = new array<string>();
			
			JsonFileLoader<array<string>>.JsonLoadFile(playerJsonPath, playerSkillsData);
			
			return playerSkillsData;
		}	
		
		return null;
	}
	
	//Saves player skills to json file
	private static void savePlayerSkillsData(array<string> playerSkillsData, string playerID)
	{
		string playerJsonPath = playersSkillsPath + playerID + ".json";
		
		if (FileExist(playerJsonPath))
		{
			JsonFileLoader<array<string>>.JsonSaveFile(playerJsonPath, playerSkillsData);
		}	
	}
	
	//Init 
	static void initPlayerLog(string playerID)
	{
		string playerJson = playersSkillsPath + playerID + ".json";
	
		if (!FileExist(playerJson))
		{
			array<string> playerSkillsData = new array<string>();
		
			JsonFileLoader<array<string>>.JsonSaveFile(playerJson, playerSkillsData);
		}
	}
	
	//Serverside skill processing
	static void processPlayerSkills_S(PlayerBase player, SkillBook book)
	{
		array<string> playerSkills = new array<string>();
		playerSkills = loadPlayerSkillData(player.GetIdentity().GetId());
		
		if (!checkIfPlayerHasSkill(playerSkills, book.getLevelName()))
		{
			playerSkills.Insert(book.getLevelName());
			
			//Save to json and save in serverside variable
			savePlayerSkillsData(playerSkills, player.GetIdentity().GetId());
					
			//Remove item from hands
			if (player.GetItemInHands())
			{
				book.Delete();
			}
		}
	}
}