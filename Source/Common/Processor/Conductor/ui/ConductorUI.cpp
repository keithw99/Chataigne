/*
  ==============================================================================

    ConductorUI.cpp
    Created: 5 Oct 2021 9:40:58pm
    Author:  bkupe

  ==============================================================================
*/

ConductorUI::ConductorUI(Conductor* conductor) :
    ActionUI(conductor, true),
    processorManagerUI(&conductor->processorManager, false)
{
    addAndMakeVisible(&processorManagerUI);
    contentComponents.add(&processorManagerUI);
    processorManagerUI.noItemText = "";

    cueUI.reset(conductor->nextCueIndex->createStepper());
    cueUI->showLabel = false;
    addAndMakeVisible(cueUI.get());

    baseBGColor = Colours::rebeccapurple.darker().withSaturation(.5f);

    nextCueUI.reset(conductor->nextCueName->createStringParameterUI());
    nextCueUI->showLabel = false;
    nextCueUI->useCustomTextColor = true;
    nextCueUI->customTextColor = TEXT_COLOR;
    nextCueUI->updateUIParams();
    addAndMakeVisible(nextCueUI.get());


    processorManagerUI.resized();
    updateProcessorManagerBounds();
}

ConductorUI::~ConductorUI()
{
}

void ConductorUI::updateBGColor()
{
    ProcessorUI::updateBGColor();
}

void ConductorUI::resizedInternalHeader(Rectangle<int>& r)
{
    ActionUI::resizedInternalHeader(r);
    cueUI->setBounds(r.removeFromRight(60).reduced(1));
    nextCueUI->setBounds(r.removeFromRight(80));
}

void ConductorUI::resizedInternalContent(Rectangle<int>& r)
{
    if (inspectable.wasObjectDeleted() || item->miniMode->boolValue()) return;
    r.setHeight(jmax(processorManagerUI.headerSize, processorManagerUI.getHeight()));
    processorManagerUI.setBounds(r);
}

void ConductorUI::updateProcessorManagerBounds()
{
    if (inspectable.wasObjectDeleted() || item->miniMode->boolValue()) return;
    int th = getHeightWithoutContent() + processorManagerUI.getHeight();
    if (th != getHeight())
    {
        item->listUISize->setValue(th);
        resized();
    }
}

void ConductorUI::itemUIAdded(ProcessorUI* pui)
{
    //updateProcessorManagerBounds();
}

void ConductorUI::itemUIRemoved(ProcessorUI* pui)
{
    //updateProcessorManagerBounds();
}

void ConductorUI::childBoundsChanged(Component* c)
{
    updateProcessorManagerBounds();
}
