#include "Ticker.h"

Ticker::Ticker(Engine* engine)
{
    this->engine = engine;

    engine->getPanel()->setChecked(1, true);

    engine->getPanel()->buttonClickEvent.subscribe([this](int event) {
        this->buttonEventHandler(event);
        return true;
    });
}

bool Ticker::update()
{
    if (status == StatusStep && needStep || status == StatusPlay) {
        needStep = false;
        return true;
    }

    return false;
}

void Ticker::buttonEventHandler(int event)
{
    if (
        event != Panel::EventButtonPause &&
        event != Panel::EventButtonStep &&
        event != Panel::EventButtonPlay
    ) {
        return;
    }

    if (event == Panel::EventButtonPause) {
        setStatus(StatusPause);
    } else if (event == Panel::EventButtonStep) {
        setStatus(StatusStep);
        needStep = true;
    } else if (event == Panel::EventButtonPlay) {
        setStatus(StatusPlay);
    }
}

void Ticker::setStatus(int val)
{
    status = val;

    engine->getPanel()->setChecked(Panel::EventButtonPause, false);
    engine->getPanel()->setChecked(Panel::EventButtonStep, false);
    engine->getPanel()->setChecked(Panel::EventButtonPlay, false);

    if (status == StatusPause || status == StatusStep) {
        engine->getPanel()->setChecked(Panel::EventButtonPause, true);
    } else if (status == StatusPlay) {
        engine->getPanel()->setChecked(Panel::EventButtonPlay, true);
    }
}
