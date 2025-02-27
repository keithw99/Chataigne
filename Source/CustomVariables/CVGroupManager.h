/*
  ==============================================================================

    CVGroupManager.h
    Created: 17 Feb 2018 10:16:11am
    Author:  Ben

  ==============================================================================
*/

#pragma once

class CustomVariablesModule;

class CVGroupManager :
	public BaseManager<CVGroup>
{
public:
	juce_DeclareSingleton(CVGroupManager, true);

	CVGroupManager(const String &name = "Custom Variables");
	~CVGroupManager();

	std::unique_ptr<CustomVariablesModule> module;

	//Input values menu
	static ControllableContainer * showMenuAndGetContainer();
	static Controllable * showMenuAndGetVariable(const StringArray& typeFilters, const StringArray& excludeTypeFilters);
	static ControllableContainer* showMenuAndGetPreset();
	static ControllableContainer * showMenuAndGetGroup();
};