class ActionReadBook: ActionSingleUseBase
{	
 	void ActionReadBook()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM_ONCE;
        m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM_ONCE;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "Read Book";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{				
		//Cast SkillBook
		SkillBook book = SkillBook.Cast(item);
		
		if (item)
		{ 				
			
			return true;		
		}
		
		return false;
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{	
		//Get Player
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		
		//Cast SkillBook
		SkillBook book = SkillBook.Cast(action_data.m_MainItem);
		
		//Process ReadBook ServerSide
		FalconSkillsLogger.processPlayerSkills_S(player, book);
	}
	
}