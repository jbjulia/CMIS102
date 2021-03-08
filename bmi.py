import os
import sys


def get_names():
    """
    Clears terminal and prompts user to input 6 names, uses default
    list if else, then calls function on list of names to get height
    and weight of each individual. If user's input is invalid, raises
    exception and exits program with exit code 1.
    """
    individuals = []
    names = ["Braden", "Corey", "Jason", "Julie", "Justin", "Steven"]

    clear_terminal()

    try:
        choice = input("Would you like to define your own names? [Y/N]:  ").lower()
        if choice == "y":
            for i in range(6):
                name = input("\nPlease add a name to the list:  ").capitalize()
                print(f"\n{name} has been added! There are {5 - len(individuals)} left to add.")
                individuals.append(name)
        elif choice == "n":
            for name in names:
                individuals.append(name)
        else:
            raise ValueError
    except ValueError:
        print("Error: Invalid input.")
        sys.exit(1)

    get_height_weight(individuals)


def get_height_weight(individuals):
    """
    Iterates list of individuals with for loop and prompts user for
    height and weight. Displays the calculated BMI for each individual
    and appends item to an array. Calls function to check BMI of each
    individual in the array, then appends the appropriate condition to
    that element of the array. Calls function to print array results.
    :param individuals: List of names
    """
    bmi_list = []

    clear_terminal()

    for name in individuals:
        try:
            height = float(input(f"\nPlease input {name}'s height (inches):  "))
            weight = float(input(f"\nPlease input {name}'s weight (pounds):  "))
            bmi = calculate_BMI(height, weight)
            bmi_list.append([name, bmi])
            clear_terminal()
            print(f"\n{name}'s Body-Mass Index (BMI) is: {bmi}. "
                  f"There are {6 - len(bmi_list)} individuals remaining.\n")
        except ValueError:
            print("Error: Height and weight must be an valid number.")
            sys.exit(1)

    bmi_list, count = check_BMI(bmi_list)
    pretty_print(bmi_list, count)


def calculate_BMI(h, w):
    """
    Calculates BMI from provided height (h) and weight (w).
    :param h: Individual's height
    :param w: Individual's weight
    :return: bmi: Rounded (2nd decimal) float of Body-Mass Index (BMI)
    """
    bmi = ((w * 703) / (h ** 2))  # Formula to calculate Body-Mass Index (BMI)

    return float(("{:.2f}".format(bmi)))


def check_BMI(bmi_list):
    """
    Checks BMI of each individual to determine weight condition, then
    appends condition to array with color-coded escape sequence.
    :param bmi_list: List of individuals and their respective BMI
    :return: bmi_list: Amended BMI list that includes condition
    :return: count: Total count of individuals per condition
    """
    underweight = 0
    normal_weight = 0
    overweight = 0

    for individual in bmi_list:
        if individual[1] < 18.5:  # BMI threshold for underweight
            individual.append("\33[93munderweight\033[0m")
            underweight += 1
        if 18.5 <= individual[1] < 25:  # BMI threshold for normal weight
            individual.append("\033[92mnormal weight\033[0m")
            normal_weight += 1
        if individual[1] >= 25:  # BMI threshold for overweight
            individual.append("\033[91moverweight\033[0m")
            overweight += 1

    count = [underweight, normal_weight, overweight]

    return bmi_list, count


def pretty_print(bmi_list, count):
    """
    Traverses BMI array and prints color-coded results for each
    individual. Prints total count of individuals for each condition.
    :param bmi_list: List of individuals with their BMI and condition
    :param count: List of totals for each condition
    """
    cyan = "\033[96m"
    end = "\033[0m"
    bold = "\033[1m"
    underline = "\033[4m"

    clear_terminal()

    print(f"{underline}BMI List - BMI and condition by individual{end}\n")

    for individual in bmi_list:
        print(f""
              f"{cyan}{individual[0]}{end} "
              f"has a BMI of {bold}{individual[1]}{end} "
              f"and is {individual[2]}.")

    print(f"\nThere are {bold}{count[0]}{end} underweight individuals, "
          f"{bold}{count[1]}{end} individuals of normal weight, and "
          f"{bold}{count[2]}{end} who are overweight.")


def clear_terminal():
    """
    Clears user's terminal depending on operating system. If exception
    arises, catches and clears terminal by printing 100 new lines.
    """
    try:
        os.system("cls" if os.name == "nt" else "clear")
    except OSError:
        print("\n" * 100)


if __name__ == "__main__":
    get_names()
    sys.exit(0)
