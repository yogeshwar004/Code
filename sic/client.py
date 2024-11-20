import socket

# Create a TCP/IP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the server's address and port
server_address = ('localhost', 8888)
client_socket.connect(server_address)
message=input("Enter  message:");
try:
    # Send data to the server
    client_socket.sendall(message.encode())
    print(f"Sent: {message}")

finally:
    # Clean up the connection
    client_socket.close()
