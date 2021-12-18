class SkillBook extends Paper
{	
	private string level;
	private string type;
	private string levelName;
	
	string getLevel()
	{
		return level;
	}
	
	void setLevel(string value)
	{
		level = value;
	}
	
	string getLevelName()
	{
		return levelName;
	}
	
	void setLevelName()
	{
		levelName = type + " " + level;
	}
	
	string getType()
	{
		return type;
	}
	
	void setType(string value)
	{
		type = value;
	}
	
	override void SetActions()
	{
		AddAction(ActionReadBook);	
	}
}