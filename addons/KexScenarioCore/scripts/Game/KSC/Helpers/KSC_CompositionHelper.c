//------------------------------------------------------------------------------------------------
class KSC_CompositionHelper
{
	//------------------------------------------------------------------------------------------------
	static void GetChildrenByXobSubstring(IEntity composition, string substr, inout notnull array<IEntity> matches, bool recursive = true)
	{
		IEntity child = composition.GetChildren();
		while (child)
		{
			if (recursive)
				GetChildrenByXobSubstring(child, substr, matches, recursive);
			
			VObject vObject = child.GetVObject();
			if (vObject && vObject.GetResourceName().IndexOf(substr) >= 0)
				matches.Insert(child);
			
			child = child.GetSibling();
		}
	}
	
	//------------------------------------------------------------------------------------------------
	static void GetChildComponentsByType(IEntity composition, typename componentType, inout notnull array<Managed> matches, bool recursive = true)
	{
		IEntity child = composition.GetChildren();
		while (child)
		{
			if (recursive)
				GetChildComponentsByType(child, componentType, matches, recursive);
			
			Managed component = child.FindComponent(componentType);
			
			if (component)
				matches.Insert(component);
			
			child = child.GetSibling();
		}
	}
}

//------------------------------------------------------------------------------------------------
class KSC_CompositionHelperT<Class T>
{
	//------------------------------------------------------------------------------------------------
	static void GetChildrenByType(IEntity composition, inout notnull array<IEntity> matches, bool recursive = true)
	{
		IEntity child = composition.GetChildren();
		while (child)
		{
			if (recursive)
				GetChildrenByType(child, matches, recursive);
			
			if (T.Cast(child))
				matches.Insert(child);
			
			child = child.GetSibling();
		}
	}
}
