/**
 * @file Dispatcher.h
 * @author RainNoise (crozzy21@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-08-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once
#include <Payload.hpp>

#include <map>
#include <string>
#include <vector>
#include <functional>

#define callback(f) std::bind(f, this, std::placeholders::_1)

namespace flatty {
/**
 * @brief Класс, описывающий вещателя событий
 * 
 */
class Dispatcher
{
private:
	/**
	 * @brief Список обработчиков события
	 * 
	 */
	std::map <std::string, std::vector<std::function<void(Payload)>>> listeners;

protected:
	/**
	 * @brief Запускает вещание события
	 * 
	 * @param eventName Имя события для вещания
	 * @param payload Передаваемые данные в событии
	 */
	void dispatch(const std::string& eventName, void* payload = nullptr);

public:
	Dispatcher() {};
	/**
	 * @brief Регистрирует нового обработчика события
	 * 
	 * 
	 * @param name Имя события для обработки
	 * @param callback указатель на функцию-обработчик события 
	 */
	void addEventListener(const std::string& eventName, const std::function<void(Payload)>& func);
};

}