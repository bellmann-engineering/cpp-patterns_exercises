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

	// TODO: Decorate thge simple Window with horizontal and vertical scrollbar
	
	std::cout << decoratedWindow->getDescription() << std::endl;

	delete simple;
	delete horiz;
	delete vert;
	delete decoratedWindow;

	return 0;
}
