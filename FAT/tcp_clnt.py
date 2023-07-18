import socket

def start_client():
    host = '127.0.0.1'
    port = 12345

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((host, port))

    while True:
        message = input("Your message: ")
        client.send(message.encode('utf-8'))
        response = client.recv(1024).decode('utf-8')
        print(f"Received from server: {response}")

    client.close()

if _name_ == "_main_":
    start_client()
