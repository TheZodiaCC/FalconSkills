modded class PlayerBase
{
	override void OnConnect()
	{
		super.OnConnect();
		
		FalconSkillsLogger.initPlayerLog(this.GetIdentity().GetId());
	}
}