#pragma once 

namespace flatty {
	
class Dispatcher;

/**
 * @brief Информация, передаваемая в обработчик события
 * 
 */
struct Payload
{
	/**
	 * @brief Указатель на объект, вещающий событие
	 * 
	 */
	Dispatcher* eventDispatcher;

	/**
	 * @brief Указатель на полезную нагрузку события
	 * 
	 */
	void* payload;
};

}