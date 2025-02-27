/*
  ==============================================================================

    MultiplexUI.cpp
    Created: 19 Dec 2020 12:12:43pm
    Author:  bkupe

  ==============================================================================
*/

MultiplexUI::MultiplexUI(Multiplex* mp) :
    ProcessorUI(mp, true),
    multiplex(mp),
    processorManagerUI(&multiplex->processorManager, false)
{
    addAndMakeVisible(&processorManagerUI);
    contentComponents.add(&processorManagerUI);
    processorManagerUI.noItemText = "";

    //itemLabel.setColour(itemLabel.textColourId, BG_COLOR);

    previewUI.reset(multiplex->previewIndex->createStepper());
    addAndMakeVisible(previewUI.get());

    baseBGColor = Colours::deepskyblue.darker().withSaturation(.4f);
    updateBGColor();

    processorManagerUI.resized();
    updateProcessorManagerBounds();
}

MultiplexUI::~MultiplexUI()
{
}

void MultiplexUI::resizedInternalHeader(Rectangle<int>& r)
{
    ProcessorUI::resizedInternalHeader(r);
    previewUI->setBounds(r.removeFromRight(60).reduced(1));
}

void MultiplexUI::resizedInternalContent(Rectangle<int>& r)
{
    if (inspectable.wasObjectDeleted() || item->miniMode->boolValue()) return;
    r.setHeight(jmax(processorManagerUI.headerSize, processorManagerUI.getHeight()));
    processorManagerUI.setBounds(r);
}

void MultiplexUI::updateProcessorManagerBounds()
{
    if (inspectable.wasObjectDeleted() || item->miniMode->boolValue()) return;
    int th = getHeightWithoutContent() + processorManagerUI.getHeight();
    if (th != getHeight())
    {
        item->listUISize->setValue(th);
        resized();
    }
}

void MultiplexUI::itemUIAdded(ProcessorUI* pui)
{
    //updateProcessorManagerBounds();
}

void MultiplexUI::itemUIRemoved(ProcessorUI* pui)
{
    //updateProcessorManagerBounds();
}

void MultiplexUI::childBoundsChanged(Component* c)
{
    updateProcessorManagerBounds();
}
