def show_hostel_options():
    # Displaying available hostel types and their prices
    print("\nAvailable Hostel Types and Prices:")
    print("1. Male - $30 per day")
    print("2. Female - $25 per day")
    print("3. Mixed - $35 per day")

def show_additional_options():
    # Displaying additional services and their prices
    print("\nAdditional Services Available:")
    print("1. Breakfast - $5 per day")
    print("2. Laundry - $10 per day")
    print("3. None (No additional services)")

def get_user_input():
    # Asking for user input and validating it
    name = input("\nCan I know your pretty name? ")

    # Ask for the type of hostel and validate input
    while True:
        print("\nPlease choose a hostel type:")
        show_hostel_options()
        hostel_type = input("Enter the number corresponding to your choice: ")

        if hostel_type == '1':
            hostel_type = 'Male'
            price_per_day = 30
            break
        elif hostel_type == '2':
            hostel_type = 'Female'
            price_per_day = 25
            break
        elif hostel_type == '3':
            hostel_type = 'Mixed'
            price_per_day = 35
            break
        else:
            print("Invalid choice, please select 1, 2, or 3.")
    
    # Ask for the duration of the stay
    while True:
        try:
            duration = int(input("\nEnter the duration of your stay (in days): "))
            if duration <= 0:
                print("Duration must be greater than 0. Please enter a valid number.")
            else:
                break
        except ValueError:
            print("Invalid input! Please enter a valid number for duration.")

    # Ask if the user wants additional services
    additional_price = 0
    while True:
        print("\nWould you like any additional services?")
        show_additional_options()
        additional_choice = input("Enter the number corresponding to your choice: ")

        if additional_choice == '1':
            additional_price = 5 * duration
            break
        elif additional_choice == '2':
            additional_price = 10 * duration
            break
        elif additional_choice == '3':
            break
        else:
            print("Invalid choice, please select 1, 2, or 3.")

    # Ask for the arrival time
    arrival_time = input("\nWhat time do you plan to arrive? (Please enter in HH:MM format): ")

    return name, hostel_type, price_per_day, duration, additional_price, arrival_time

def calculate_total_price(price_per_day, duration, additional_price):
    # Calculating the total price
    return (price_per_day * duration) + additional_price

def hostel_booking():
    # Display the welcome message
    print("Welcome to my hostel!")

    # Get user input for booking details
    name, hostel_type, price_per_day, duration, additional_price, arrival_time = get_user_input()

    # Calculate total cost
    total_price = calculate_total_price(price_per_day, duration, additional_price)

    # Display Q&A format and booking confirmation
    

    print(f"Your hostel booking details:")
    print(f"->Booking confirmed for {name}. You have booked a {hostel_type} hostel for {duration} days.")
    print(f"->Total price for your stay: ${total_price}")

# Main program
if __name__ == "__main__":
    hostel_booking()
