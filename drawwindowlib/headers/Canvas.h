#pragma once

#include <QLabel>
#include <functional>
#include <QMouseEvent>
#include <QEvent>

using namespace std;

class Canvas : public QLabel{

	Q_OBJECT

	public:
		Canvas();

		void setMousePressCallback(function<void(int, int, Qt::MouseButton)> f);
		void setMouseMoveCallback(function<void(int, int)> f);
		void setMouseReleaseCallback(function<void(int, int, Qt::MouseButton)> f);

		void setKeyPressCallback(function<void(Qt::Key)> f);
		void setKeyReleaseCallback(function<void(Qt::Key)> f);

	protected:

		void mousePressEvent(QMouseEvent* event);
		void mouseMoveEvent(QMouseEvent* event);
		void mouseReleaseEvent(QMouseEvent* event);

		function<void(int, int, Qt::MouseButton)> mousePressCallback;
		function<void(int, int)> mouseMoveCallback;
		function<void(int, int, Qt::MouseButton)> mouseReleaseCallback;

		void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);

		function<void(Qt::Key)> keyPressCallback;
		function<void(Qt::Key)> keyReleaseCallback;

};

