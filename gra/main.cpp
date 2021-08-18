#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
using namespace std;
using namespace sf;


template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right()
    && A.bottom() >= B.top() && A.top() <= B.bottom();
}
    bool collisionTest(Paddle& paddle, Ball& ball)
    {
        if(!isIntersecting(paddle, ball)) return false;

        ball.moveUp();

        if(ball.getPosition().x < paddle.getPosition().x)
        {
            ball.moveLeft();
        }
        else if (ball.getPosition().x > paddle.getPosition().x)
        {
            ball.moveRight();
        }
    }



int main()
{
    Ball ball(400,300);
    Paddle paddle(400, 550);
    RenderWindow okno{ VideoMode{800,600}, "Gra w sfml"};
    okno.setFramerateLimit(60);
    Event event;
    while(true)
    {
     okno.clear(Color::Black);
     okno.pollEvent(event);
     if (event.type == Event::Closed)
     {
         okno.close();
         break;
     }
     ball.update();
     paddle.update();
    collisionTest(paddle, ball);
    okno.draw(ball);
    okno.draw(paddle);
    okno.display();
    }

    return 0;
}
