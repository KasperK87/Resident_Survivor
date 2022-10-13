using SFML.Graphics;
using SFML.Window;

namespace Resident_Survivor {
    class Game
    {
        private const int WIDTH = 640;
        private const int HEIGHT = 480;
        private const string TITLE = "Resident Survivor";
        private RenderWindow window;
        private VideoMode mode = new VideoMode(WIDTH, HEIGHT);
        
        public Game()
        {
            this.window = new RenderWindow(this.mode, TITLE);
            
            this.window.SetVerticalSyncEnabled(true);
            this.window.Closed += (sender, args) => {
                this.window.Close(); 
            };
        }

        public void run() 
        {
            while(this.window.IsOpen)
            {
                this.handleEvents();
                this.update();
                this.draw();            
            }
        }

        private void handleEvents()
        {
            this.window.DispatchEvents();
        }
        private void update() {}

        private void draw() 
        {
            this.window.Clear(Color.Blue);
            this.window.Display();
        }
        
    }
}