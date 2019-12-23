using System;

namespace Nano_Sat_Control
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "NANO-SAT-01 Ground Station Control";
            UDPSocket c = new UDPSocket();
            Console.WriteLine("Enter the ip address of the satellite");
            string ip_address = Console.ReadLine();
            try
            {
                c.Client(ip_address, 2390);
            }
            catch
            {
                Console.WriteLine("Error while connecting to the satellite");
            }

            c.Send("ConnectionRequest_S01");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Establishing connection...\n\n");
            Console.ForegroundColor = ConsoleColor.White;
            
            while (true)
            {
                string command = Console.ReadLine();
                if (command == "exit")
                {
                    break;
                } else if (command == "help" || command == "?")
                {
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    Console.BackgroundColor = ConsoleColor.Red;
                    Console.WriteLine("NANO-SAT-01 CONTROL HELP SHEET                                             ");
                    Console.WriteLine("-help OR ?                               Shows this help list              ");
                    Console.WriteLine("-exit                                    Exit terminal                     ");
                    Console.WriteLine("-cmd_senddata_timealive                  Shows the active time             ");
                    Console.WriteLine("-cmd_senddata_humtemp                    Shows the humidity and temperature");
                    Console.WriteLine("-cmd_requestaction_led1on                Turns the LED1 on                 ");
                    Console.WriteLine("-cmd_requestaction_led1off               Turns the LED1 off                ");
                    Console.WriteLine("-cmd_requestaction_led2on                Turns the LED2 on                 ");
                    Console.WriteLine("-cmd_requestaction_led2off               Turns the LED2 off                ");
                    Console.WriteLine("-cmd_requestaction_buzzeron              Turns the BUZZER on               ");
                    Console.WriteLine("-cmd_requestaction_buzzeroff             Turns the BUZZER off              ");
                    Console.WriteLine("");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.BackgroundColor = ConsoleColor.Black;
                }
                else
                {
                    c.Send(command);
                }
            }
        }
    }
}
