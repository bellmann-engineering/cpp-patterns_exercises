#include <iostream> 
#include <string>

using namespace std;
 
class Window 
{
    public:
        virtual void draw() = 0;
        virtual string getDescription() = 0;
        virtual ~Window() {};
};
 
class SimpleWindow : public Window 
{
    public:
        void draw() 
        {
            // if this was a gui app draw window 
        }
        string getDescription() 
        {
            return "Simple window";
        }
};

class WindowDecorator : public Window 
{
    protected:
        Window* m_decoratedWindow; 
    
    public:
        // TODO: create constructor to set m_decoratedWindow
	    // TODO: do not forget about a destructor
};

class VerticalScrollBarDecorator : public WindowDecorator 
{
    public:
        VerticalScrollBarDecorator(Window* decoratedWindow) 
           : WindowDecorator(decoratedWindow) 
        {

        }
    
        void draw() 
        {
            drawVerticalScrollBar();
            m_decoratedWindow->draw();
        }
    
        string getDescription() 
        {
            return m_decoratedWindow->getDescription() + " with vertical scrollbar";
        }

    private:
        void drawVerticalScrollBar() 
        {
            // if this was a gui app draw vertical scrollbar
			// cout...
        }
};

class HorizontalScrollBarDecorator : public WindowDecorator 
{
    // TODO: implement the HorizontalScrollBarDecorator
};

int main()
{
	Window* simple = new SimpleWindow();
	std::cout << simple->getDescription() << std::endl;

	Window* horiz = new HorizontalScrollBarDecorator(new SimpleWindow());
	std::cout << horiz->getDescription() << std::endl;

	Window* vert = new VerticalScrollBarDecorator(new SimpleWindow());
	std::cout << vert->getDescription() << std::endl;

	Window* decoratedWindow = new HorizontalScrollBarDecorator(
					new VerticalScrollBarDecorator(new SimpleWindow()));
	std::cout << decoratedWindow->getDescription() << std::endl;

	delete simple;
	delete horiz;
	delete vert;
	delete decoratedWindow;

	return 0;
}
