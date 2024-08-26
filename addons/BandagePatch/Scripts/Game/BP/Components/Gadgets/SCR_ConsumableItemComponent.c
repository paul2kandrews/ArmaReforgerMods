//------------------------------------------------------------------------------------------------
modded class SCR_ConsumableItemComponent : SCR_GadgetComponent
{
	//------------------------------------------------------------------------------------------------
	override protected void OnApplyToCharacter(IEntity item, bool successful, ItemUseParameters animParams)
	{
		if (Replication.IsServer() && SCR_ConsumableBandage.Cast(GetConsumableEffect()))
			Rpc(RpcDo_FB_ClearInvokersBroadcast, animParams.GetIntParam());
		
		super.OnApplyToCharacter(item, successful, animParams);
	}
	
	//------------------------------------------------------------------------------------------------
	[RplRpc(RplChannel.Reliable, RplRcver.Broadcast)]
	protected void RpcDo_FB_ClearInvokersBroadcast(int targetGroup)
	{
		ClearInvokers(targetGroup);
	}
}
