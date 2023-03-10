#include <whippch.h>
#include <Platform/Windows/WindowsInput.h>
#include <Whip/Core/Application.h>

#include <GLFW/glfw3.h>

_WHIP_START

input* input::s_instance = new windows_input();

WHP_NODISCARD bool windows_input::is_key_pressed_impl(int keycode)
{
	auto window = static_cast<GLFWwindow*>(application::get().get_window().get_native_window());
	int state = glfwGetKey(window, keycode);
	bool is_pressed = ((state == GLFW_PRESS) || (state == GLFW_REPEAT));
	return is_pressed;
}

WHP_NODISCARD bool windows_input::is_mouse_button_pressed_impl(int button)
{
	auto window = static_cast<GLFWwindow*>(application::get().get_window().get_native_window());
	int state = glfwGetMouseButton(window, button);
	bool is_pressed = (state == GLFW_PRESS);
	return is_pressed;
}

WHP_NODISCARD float windows_input::get_mouse_posx_impl()
{
	auto [posX, posY] = get_mouse_pos_impl();
	return posX;
}

WHP_NODISCARD float windows_input::get_mouse_posy_impl()
{
	auto[posX, posY] = get_mouse_pos_impl();
	return posY;
}

WHP_NODISCARD pair<float, float> windows_input::get_mouse_pos_impl()
{
	auto window = static_cast<GLFWwindow*>(application::get().get_window().get_native_window());
	double posX, posY;
	glfwGetCursorPos(window, &posX, &posY);
	return { (float)posX, (float)posY };
}

_WHIP_END