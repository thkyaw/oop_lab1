#include "TicketSystem.hpp"

int CheckTicketPrice(Order ticket) {
    if (ticket.quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative");
    }

    int price_per_ticket = 0;

    switch (ticket.type) {
        case TicketType::Adult:
            price_per_ticket = 350;  // Adult ticket price
            break;
        case TicketType::Child:
            price_per_ticket = 280;  // Child ticket price
            break;
        case TicketType::Elder:
            price_per_ticket = 240;  // Elder ticket price
            break;
        default:
            throw std::invalid_argument("Invalid ticket type");
    }

    int total_price = price_per_ticket * ticket.quantity;

    if (ticket.quantity >= 10) {
        total_price = static_cast<int>(total_price * 0.8);  // 20% discount
    }

    return total_price;
}

int CheckTodaySales(std::vector<Order> tickets) {
    int total_sales = 0;

    for (const auto& ticket : tickets) {
        if (ticket.quantity < 0) {
            throw std::invalid_argument("Quantity cannot be negative");
        }
        total_sales += CheckTicketPrice(ticket);
    }

    return total_sales;
}

int CheckTodayTicketSales(std::vector<Order> tickets) {
    int total_tickets = 0;

    for (const auto& ticket : tickets) {
        if (ticket.quantity < 0) {
            throw std::invalid_argument("Quantity cannot be negative");
        }
        total_tickets += ticket.quantity;
    }

    return total_tickets;
}

int CheckSpecificTicketSales(TicketType type, std::vector<Order> tickets) {
    int specific_ticket_sales = 0;

    for (const auto& ticket : tickets) {
        if (ticket.type == type) {
            specific_ticket_sales += CheckTicketPrice(ticket);
        }
    }

    return specific_ticket_sales;
}

int CheckSpecificOrdersTicketPrice(int idx, std::vector<Order> tickets) {
    if (idx < 0 || idx >= static_cast<int>(tickets.size())) {
        throw std::invalid_argument("Invalid order index");
    }

    return CheckTicketPrice(tickets[idx]);
}
