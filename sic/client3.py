import asyncio
import websockets

async def chat_client():
    # Replace <server-ip> with the Raspberry Pi's IP address
    async with websockets.connect("ws://192.168.167.220:8765") as websocket:
        print("Connected to the server")
        while True:
            # Send a message to the server
            message = input("Enter message: ")
            await websocket.send(message)
            print(f"Message sent: {message}")

            # Wait for a reply
            reply = await websocket.recv()
            print(f"Received: {reply}")

# Run the client
asyncio.run(chat_client())