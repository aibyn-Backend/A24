import asyncio

async def task1():
    print("жду 5 секунд  загрузка файла")
    await asyncio.sleep(5)
    print("файл загружен")

async def task2():
    print("жду 10 секунд проверка процессора")
    await asyncio.sleep(10)
    print("процессор проверен")

async def main():
    await asyncio.gather(task1(),task2())

if __name__ == "__main__":
    asyncio.run(main())
