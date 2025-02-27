/*
  ==============================================================================

    Conductor.h
    Created: 5 Oct 2021 9:35:28pm
    Author:  bkupe

  ==============================================================================
*/

#pragma once

class ConductorCue;

class Conductor :
    public Action,
    public ProcessorManager::ManagerListener,
    public Action::ActionListener
{
public:
    Conductor(var params = var(), Multiplex * multiplex = nullptr);
    ~Conductor();

    IntParameter* nextCueIndex;
    BoolParameter* loop;
    StringParameter* currentCueName;
    StringParameter* nextCueName;

    ConductorCue* currentCue;
    BoolParameter* cueTriggerSetCurrent;

    ProcessorManager processorManager;

    void onContainerParameterChangedInternal(Parameter* p) override;

    void updateDisables(bool force) override;

    void itemAdded(Processor* p) override;
    void itemsAdded(Array<Processor*> p) override;
    void itemRemoved(Processor* p) override;
    void itemsRemoved(Array<Processor *> p) override;
    void itemsReordered() override;

    void actionTriggered(Action* a, bool triggerTrue, int multiplexIndex = 0) override;

    void updateIndices();

    void triggerConsequences(bool triggerTrue, int multiplexIndex = 0) override;

    int getValidIndexAfter(int index = 0);

    void updateNextCue();

    void afterLoadJSONDataInternal() override;

    ProcessorUI* getUI() override;
    String getTypeString() const override { return "Conductor"; };
};
