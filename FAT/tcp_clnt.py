import socket
import threading

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 12345))

    def receive_messages():
        while True:
            data = client_socket.recv(1024).decode('utf-8')
            if not data:
                break
            print("Server:", data)

    receive_thread = threading.Thread(target=receive_messages)
    receive_thread.start()

    while True:
        message = input()
        if message.lower() == 'exit':
            break

        client_socket.send(message.encode('utf-8'))

    client_socket.close()

if __name__ == "__main__":
    start_client()