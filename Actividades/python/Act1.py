"""
Actividad 1.1. Planteamiento e Implementación de algoritmos
Author: Alejandra Cabrera Ruíz 
Author: Carlos Rodrigo Salguero Alcántara
Author: Sergio Garnica González
Date: 14/08/23
"""


import random

def days_to_produce(num_shirts: int) -> int:
    """
    Returns the number of days it takes to produce a given number of shirts.
    :param num_shirts: The number of shirts to produce.
    :return: The number of days it takes to produce the given number of shirts.
    """
    if(num_shirts <= 0):
        return 0
    
    n: int = random.randint(1, 10)
    m: int = random.randint(1, 10)

    print("Shirts produced: " + str(n+m))
    
    if(num_shirts <= (n + m)):
        return 1
    
    return 1 + days_to_produce(num_shirts - (n + m))


def fill_sodas(mililiters: int) -> int:
    """
    Returns the number of sodas that can be filled in a cilinder.
    :param mililiters: The number of mililiters to fill.
    :return: The number of sodas that can be filled in a cilinder.
    """


    if(mililiters <= 0):
      return 0

    cilinder_height: int = random.randint(6, 10) # cm
    cilinder_radius: int = random.randint(1, 5) # cm

    pi: float = 3.1416

    cilinder_volume: int = (pi * (cilinder_radius ** 2)) * cilinder_height # cm^3 = ml   

    if(cilinder_volume < mililiters): 
      return 0

    print("Total cilinder capacity: " + str(cilinder_volume) + "\n")

    sodas: int = cilinder_volume // mililiters

    return sodas

    
def run():
    print("EXERCISE 1: \n")
    N: int = random.randint(1, 100)
    print("Shirts to produce: " + str(N) + "\n")
    print("\nDays to produce: " + str(days_to_produce(N)))

    print("\nEXERCISE 2: \n")
    M: int = random.randint(1, 10)
    print("Mililiters to fill: " + str(M) + "\n")
    print("\nSodas filled: " + str(fill_sodas(M)))


if __name__ == "__main__":
    run()