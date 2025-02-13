// #include "0001/Son.h"
#include <iostream>
#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

/* Main */
int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
	sf::RenderWindow window(sf::VideoMode(640, 480), "IMGUI + SFML");
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Clock deltaClock;
	while (window.isOpen( )) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) { window.close( ); }
		}
		ImGui::SFML::Update(window, deltaClock.restart( ));
		ImGui::Begin("Hello, World!!!");
		ImGui::Button("This is a button");
		ImGui::End( );

		window.clear( );
		window.draw(shape);
		ImGui::SFML::Render(window);
		window.display( );
	}
	ImGui::SFML::Shutdown( );
	return 0;
}	//	Main