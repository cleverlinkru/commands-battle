#pragma once
#include <vector>
#include <functional>

template<typename... Args>
class Event
{
    public:
        void subscribe(std::function<bool(Args...)> listener)
        {
            listeners.push_back(listener);
        }

        void raise(Args... args)
        {
            for (const auto& listener : listeners) {
                bool surfacing = listener(args...);
                if (!surfacing) {
                    break;
                }
            }
        }

    private:
        std::vector<std::function<bool(Args...)>> listeners;
};
