#pragma once

#include <QApplication>
#include <QLabel>
#include <QPainter>
#include <functional>
#include <QObject>
#include <QTimer>
#include "Canvas.h"

using namespace std;

namespace DrawWindowLib{

	/**
	* A class representing a window shown on the screen.
	*
	* This class represents a window that will be shown on the screen and on
	* which you can draw things. Use the method getPainter to get a QPainter
	* you can use to draw with, and then call the method commitPainterChanges
	* to update the window to reflect the drawing changes you made with the
	* QPainter object.
	*
	* The window uses the following coordinate system:
	*
	*  0
	*  |
	*0-+-------> x
	*  |
	*  |
	*  v
	*  y
	*
	* You must call the method start in order to show the window on the screen.
	*/
	class DrawWindow : private QObject{

		Q_OBJECT

	public:
		/**
		* Creates a new Window.
		*
		* Creates a new Window with the given width and height (excluding the
		* borders).
		*
		* @param width The width of the window.
		* @param height The height of the window.
		*/
		DrawWindow(const int width, const int height);

		/**
		* Returns a QPainter you can use to draw things in the window.
		*
		* This method gives you a QPainter object you can use to draw things
		* in the window. See the documentation for QPainter here:
		* http://doc.qt.io/qt-5/qpainter.html. When you're done with your
		* changes, you must call the method commitPainterChanges in order to
		* update the window to reflect the changes.
		*
		* @return A QPainter to draw things with in the window.
		*/
		QPainter* getPainter();

		/**
		* Updates the window with the drawing changes made by the QPainter.
		*
		* Updates the window with the drawing changes made by the QPainter
		* obtained via the method getPainter.
		*/
		void commitPainterChanges();

		/**
		* Regularly calls a function with a given interval.
		*
		* Calls the function f with the interval intervalInMs miliseconds (the
		* first call to f will take place after intervalInMs miliseconds).
		*
		* Note: this method may only be called once and must be called before
		* start is called.
		*
		* Example usage:
		* theDrawWindow.setInterval(200, [&](){
		*   // Code here is executed 5 times per second.
		* });
		*
		* @parameter intervalInMs The interval in miliseconds.
		* @parameter f() The function to call.
		*/
		void setInterval(const int intervalInMs, function<void()> f);

		/**
		* Starts calling a function when a mouse button is pressed.
		*
		* Calls the function f when a mouse button is pressed down. Passed along
		* as arguments are the x and y coordinates where the press took place, as
		* well as an Qt::MouseButton value indicating which button that was
		* pressed.
		*
		* Note: this method may only be called once and must be called before
		* start is called.
		*
		* Example usage:
		* theDrawWindow.setMousePressCallback([&](int x, int y, Qt::MouseButton button){
		*   // Code here is executed each time a mouse button is pressed.
		* });
		*
		* @parameter f(int, int) The function to call.
		*/
		void setMousePressCallback(function<void(int, int, Qt::MouseButton)> f);

		/**
		* Starts calling a function when the mouse is moved.
		*
		* Calls the function f when the mouse moves over the window. Passed along
		* as arguments are the new x and y coordinates for the mouse.
		*
		* Note: this method may only be called once and must be called before
		* start is called.
		*
		* Example usage:
		* theDrawWindow.setMouseMoveCallback([&](int x, int y){
		*   // Code here is executed each time the mouse moves over the window.
		* });
		*
		* @parameter f(int, int) The function to call.
		*/
		void setMouseMoveCallback(function<void(int, int)> f);

		/**
		* Starts calling a function when a mouse button is released.
		*
		* Calls the function f when a mouse button is released. Passed along
		* as arguments are the x and y coordinates where the release took place, as
		* well as an Qt::MouseButton value indicating which button that was
		* released.
		*
		* Note: this method may only be called once and must be called before
		* start is called.
		*
		* Example usage:
		* theDrawWindow.setMouseRelaseCallback([&](int x, int y, Qt::MouseButton button){
		*   // Code here is executed each time a mouse button is released.
		* });
		*
		* @parameter f(int, int, int) The function to call.
		*/
		void setMouseReleaseCallback(function<void(int, int, Qt::MouseButton)> f);

		/**
		* Starts calling a function when a key is pressed.
		*
		* Calls the function f when a key is pressed. Passed along is an
		* Qt::Key value indicating which key that was pressed.
		*
		* Note: this method may only be called once and must be called before
		* start is called.
		*
		* Example usage:
		* theDrawWindow.setKeyPressCallback([&](Qt::Key key){
		*   // Code here is executed each time a key is pressed.
		* });
		*
		* @parameter f(Qt::Key) The function to call.
		*/
		void setKeyPressCallback(function<void(Qt::Key)> f);

		/**
		* Starts calling a function when a key is released.
		*
		* Calls the function f when a key is released. Passed along is an
		* Qt::Key value indicating which key that was released.
		*
		* Note: this method may only be called once and must be called before
		* start is called.
		*
		* Example usage:
		* theDrawWindow.setKeyRelaseCallback([&](Qt::Key key){
		*   // Code here is executed each time a key is released.
		* });
		*
		* @parameter f(Qt::Key) The function to call.
		*/
		void setKeyReleaseCallback(function<void(Qt::Key)> f);

		/**
		* Starts the window and shows it on the screen. This method returns
		* when the window is closed down.
		*/
		void start();

	private:
		QApplication app;
		QPixmap pixmap; // Functions as the canvas.
		QPainter painter; // Painter for drawing on the canvas.
		Canvas canvas; // Widget for showing the canvas.

		QTimer *timer;
		function<void()> timerCallback;

		private slots:
		void onTime();

	};

}
