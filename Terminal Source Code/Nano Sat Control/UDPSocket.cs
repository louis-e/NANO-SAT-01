//UDPSocket.cs
//Simple C# UDP Server/Client in 70 lines
//https://gist.github.com/louis-e/888d5031190408775ad130dde353e0fd

using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Nano_Sat_Control
{
    public class UDPSocket
    {
        private Socket _socket;
        private const int bufSize = 8 * 1024;
        private State state = new State();
        private EndPoint epFrom = new IPEndPoint(IPAddress.Any, 0);
        private AsyncCallback recv = null;

        public class State
        {
            public byte[] buffer = new byte[bufSize];
        }

        public void Server(string address, int port)
        {
            _socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            _socket.SetSocketOption(SocketOptionLevel.IP, SocketOptionName.ReuseAddress, true);
            _socket.Bind(new IPEndPoint(IPAddress.Parse(address), port));
            Receive();
        }

        public void Client(string address, int port)
        {
            _socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            _socket.Connect(IPAddress.Parse(address), port);
            Receive();
        }

        public void Send(string text)
        {
            byte[] data = Encoding.ASCII.GetBytes(text);
            _socket.BeginSend(data, 0, data.Length, SocketFlags.None, (ar) =>
            {
                State so = (State)ar.AsyncState;
                int bytes = _socket.EndSend(ar);
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Transmitted " + bytes + " bytes over UDP\n");
                Console.Beep(1000, 100);
                Console.ForegroundColor = ConsoleColor.White;
            }, state);
        }

        private void Receive()
        {
            _socket.BeginReceiveFrom(state.buffer, 0, bufSize, SocketFlags.None, ref epFrom, recv = (ar) =>
            {
                try
                {
                    State so = (State)ar.AsyncState;
                    int bytes = _socket.EndReceiveFrom(ar, ref epFrom);
                    _socket.BeginReceiveFrom(so.buffer, 0, bufSize, SocketFlags.None, ref epFrom, recv, so);
                    Console.WriteLine("Received from NANO-SAT-01 (" + epFrom.ToString() + ") " + bytes + " bytes");
                    Console.Beep(1700, 700);
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine(Encoding.ASCII.GetString(so.buffer, 0, bytes) + "\n");
                    Console.ForegroundColor = ConsoleColor.White;
                }
                catch { }

            }, state);
        }
    }
}