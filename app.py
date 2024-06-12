# import aiohttp
# import asyncio
# import time
# import psutil

# API_URL = "http://localhost:3000/"
# PYTHON_CODE = {
#     "code": """import resource
# import time

# # Set CPU time limit to 2 seconds
# resource.setrlimit(resource.RLIMIT_CPU, (2, 2))

# # Set memory limit to 256MB
# resource.setrlimit(resource.RLIMIT_AS, (256 * 1024 * 1024, 256 * 1024 * 1024))

# # Example code that will be limited
# print("Starting a task that will consume resources...")

# try:
#     while True:
#         pass  # Infinite loop to consume CPU time
# except Exception as e:
#     print(f"Exception occurred: {e}")
# finally:
#     print("Finished task")

# """
# }

# async def fetch(session, url, data):
#     async with session.post(url, json=data) as response:
#         return await response.text()

# def print_system_utilization():
#     print(f"CPU Usage: {psutil.cpu_percent(interval=1)}%")
#     print(f"Memory Usage: {psutil.virtual_memory().percent}%")

# async def main():
#     async with aiohttp.ClientSession() as session:
#         tasks = []
#         for _ in range(1):
#             task = asyncio.create_task(fetch(session, API_URL, PYTHON_CODE))
#             tasks.append(task)

#         print("Before 1 request:")
#         print_system_utilization()
        
#         start_time = time.time()
#         responses = await asyncio.gather(*tasks)
#         end_time = time.time()

#         print(f"Total time taken 1 req: {end_time - start_time} seconds")
#         print("After 1 request:")
#         print_system_utilization()

#     async with aiohttp.ClientSession() as session:
#         tasks = []
#         for _ in range(10):
#             task = asyncio.create_task(fetch(session, API_URL, PYTHON_CODE))
#             tasks.append(task)

#         print("Before 10 requests:")
#         print_system_utilization()
        
#         start_time = time.time()
#         responses = await asyncio.gather(*tasks)
#         end_time = time.time()

#         print(f"Total time taken 10 req: {end_time - start_time} seconds")
#         print("After 10 requests:")
#         print_system_utilization()
    
#     # async with aiohttp.ClientSession() as session:
#     #     tasks = []
#     #     for _ in range(100):
#     #         task = asyncio.create_task(fetch(session, API_URL, PYTHON_CODE))
#     #         tasks.append(task)

#     #     print("Before 100 requests:")
#     #     print_system_utilization()
        
#     #     start_time = time.time()
#     #     responses = await asyncio.gather(*tasks)
#     #     end_time = time.time()

#     #     print(f"Total time taken 100 req: {end_time - start_time} seconds")
#     #     print("After 100 requests:")
#     #     print_system_utilization()

#     # async with aiohttp.ClientSession() as session:
#     #     tasks = []
#     #     for _ in range(1000):
#     #         task = asyncio.create_task(fetch(session, API_URL, PYTHON_CODE))
#     #         tasks.append(task)

#     #     print("Before 1000 requests:")
#     #     print_system_utilization()
        
#     #     start_time = time.time()
#     #     responses = await asyncio.gather(*tasks)
#     #     end_time = time.time()

#     #     print(f"Total time taken 1000 req: {end_time - start_time} seconds")
#     #     print("After 1000 requests:")
#     #     print_system_utilization()

# if __name__ == "__main__":
#     asyncio.run(main())

def remove_digits(s):
    while any(char.isdigit() for char in s):  # Check if there are any digits left in the string
        for i in range(len(s)):
            if s[i].isdigit():  # Find the first digit
                # Find the closest non-digit character to the left
                for j in range(i - 1, -1, -1):
                    if not s[j].isdigit():
                        # Remove both characters
                        s = s[:j] + s[j + 1:i] + s[i + 1:]
                        break
                break
    return s

# Example usage
s = "cab34"
result = remove_digits(s)
print(result)  # Output should be "bef"
