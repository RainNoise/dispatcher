#include <Dispatcher.hpp>

namespace flatty {

void Dispatcher::dispatch(const std::string& eventName, void* payload) {
	Payload data{};
	data.eventDispatcher = this;
	data.payload = payload;
	
	for(const auto& listener : listeners[eventName])
	{
		listener(data);
	}
}

void Dispatcher::addEventListener(const std::string& name, const std::function<void(Payload)>& func) {
	listeners[name].push_back(func);
}

}