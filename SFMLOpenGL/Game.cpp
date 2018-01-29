#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	/*corners[0] = Vector3Class(-1.0f, 1.0f, -7.0f);
	corners[1] = Vector3Class(1.0f, 1.0f, -7.0f);
	corners[2] = Vector3Class(-1.0f, 1.0f, -5.0f);
	corners[3] = Vector3Class(1.0f, 1.0f, -5.0f);
	corners[4] = Vector3Class(-1.0f, -1.0f, -7.0f);
	corners[5] = Vector3Class(1.0f, -1.0f, -7.0f);
	corners[6] = Vector3Class(-1.0f, -1.0f, -5.0f);
	corners[7] = Vector3Class(1.0f, -1.0f, -5.0f);*/
}

Game::~Game() {}

Vector3Class corners[] = { Vector3Class(-1.0f, 1.0f, -7.0f),Vector3Class(1.0f, 1.0f, -7.0f), 
Vector3Class(-1.0f, 1.0f, -5.0f), Vector3Class(1.0f, 1.0f, -5.0f), Vector3Class(-1.0f, -1.0f, -7.0f),
Vector3Class(1.0f, -1.0f, -7.0f),Vector3Class(-1.0f, -1.0f, -5.0f), Vector3Class(1.0f, -1.0f, -5.0f) };

float vertices[] = { (corners[2].X()), (corners[2].Y()), (corners[2].Z()),
(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
(corners[7].X()), (corners[7].Y()), (corners[7].Z()),
(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
(corners[1].X()), (corners[1].Y()), (corners[1].Z()),
(corners[2].X()), (corners[2].Y()), (corners[2].Z()),
(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
(corners[4].X()), (corners[4].Y()), (corners[4].Z()),
(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
(corners[1].X()), (corners[1].Y()), (corners[1].Z()) };

float colors[] = { 1.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f,
0.0f, 1.0f, 0.0f,
0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f,
0.0f, 0.0f, 1.0f,
0.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f,
1.0f, 1.0f, 0.0f,
1.0f, 1.0f, 0.0f,
0.0f, 1.0f, 1.0f,
0.0f, 1.0f, 1.0f };
unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	Matrix3 m1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < 8; inde++)
		{
			corners[inde] = m1.Rotation(1) * corners[inde];
		}
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < 8; inde++)
		{
			corners[inde] = m1.Rotation(-1) * corners[inde];
		}
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < 8; inde++)
		{
			corners[inde] = m1.Translate(.01, .01) * corners[inde];
		}
		offset = offset + Vector3Class(.01, .01, 0);
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < 8; inde++)
		{
			corners[inde] = m1.Translate(-.01, -.01) * corners[inde];
		}
		offset = offset + Vector3Class(-.01, -.01, 0);
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < 8; inde++)
		{
			corners[inde] = m1.Scale(99, 99) * corners[inde];
		}
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < 8; inde++)
		{
			corners[inde] = m1.Scale(101, 101) * corners[inde];
		}
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}

	float temp[] = { (corners[2].X()), (corners[2].Y()), (corners[2].Z()),
		(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
		(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
		(corners[7].X()), (corners[7].Y()), (corners[7].Z()),
		(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
		(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
		(corners[1].X()), (corners[1].Y()), (corners[1].Z()),
		(corners[2].X()), (corners[2].Y()), (corners[2].Z()),
		(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
		(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
		(corners[4].X()), (corners[4].Y()), (corners[4].Z()),
		(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
		(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
		(corners[1].X()), (corners[1].Y()), (corners[1].Z()) };

	std::copy(temp, temp + 42, vertices);

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

