#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <unordered_map>
#include <ostream>
using namespace std;
template <typename T>
class ReservationSystem {
public:
    struct Reservation {
        T item;
        string reserverName;
        string reserverId;
        string reserverDOB;
        chrono::system_clock::time_point reservationTime;

        Reservation(T itm, string name, string id, string dob)
            : item(itm), reserverName(name), reserverId(id), reserverDOB(dob), reservationTime(chrono::system_clock::now()) {}
    };

    bool reserveItem(const T& item, const string& name, const string& id, const string& dob) {
        auto it = find_if(reservations.begin(), reservations.end(), [&](const Reservation& r) {
            return r.item == item;
            });

        if (it != reservations.end()) {
            *it = Reservation(item, name, id, dob);
        }
        else {
            reservations.emplace_back(item, name, id, dob);
        }
        return true;
    }

    void addItems(const vector<Reservation>& items) {
        for (const auto& item : items) {
            reserveItem(item.item, item.reserverName, item.reserverId, item.reserverDOB);
        }
    }

    int reservationDuration(const T& item) const {
        auto it = find_if(reservations.begin(), reservations.end(), [&](const Reservation& r) {
            return r.item == item;
            });

        if (it == reservations.end()) return -1;

        auto now = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::seconds>(now - it->reservationTime).count();
        return static_cast<int>(duration);
    }

    void removeItem(const T& item) {
        reservations.erase(remove_if(reservations.begin(), reservations.end(), [&](const Reservation& r) {
            return r.item == item;
            }), reservations.end());
    }

    void removeItems(const vector<T>& items) {
        for (const auto& item : items) {
            removeItem(item);
        }
    }

    size_t reservationCount() const {
        return reservations.size();
    }

    friend ostream& operator<<(ostream& os, const ReservationSystem& rs) {
        for (const auto& reservation : rs.reservations) {
            os << "Item: " << reservation.item
                << ", Reserver: " << reservation.reserverName
                << ", ID: " << reservation.reserverId
                << ", DOB: " << reservation.reserverDOB
                << "\n";
        }
        return os;
    }

private:
    vector<Reservation> reservations;
};

#endif // RESERVATIONSYSTEM_H
