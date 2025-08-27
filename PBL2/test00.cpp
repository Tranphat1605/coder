// ctdl_evcs_simple.hpp
#pragma once
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;   // thêm vào đây

/// ===== Định danh =====
using StationID     = int;
using PortID        = int;
using CustomerID    = int;
using SessionID     = long long;
using ReservationID = long long;
using Money         = long long;

/// ===== Thời gian (đơn giản: tính bằng phút) =====
struct TimeSlot {
    long long start = 0; 
    long long end   = 0; 
};
struct TimeSlotLess {
    bool operator()(const TimeSlot& a, const TimeSlot& b) const {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
};

/// ===== Tọa độ & loại sạc =====
struct Coord { double lat = 0.0, lon = 0.0; };
enum class ChargerType { AC, DC_FAST, OTHER };
enum class PortStatus  { IDLE, CHARGING, RESERVED, MAINTENANCE };

/// ===== Thực thể =====
struct Customer {
    CustomerID id = 0;
    string name;
    string phone;
    vector<SessionID> session_history;
};

struct Session {
    SessionID id = 0;
    CustomerID customer = 0;
    StationID  station  = 0;
    PortID     port     = 0;
    long long  start_min = 0;
    long long  end_min   = 0;  
    double     energy_kWh = 0;
    Money      revenue    = 0;
};

struct Reservation {
    ReservationID id = 0;
    CustomerID  customer = 0;
    StationID   station  = 0;
    PortID      port     = 0;
    TimeSlot    slot{};
};

struct Port {
    PortID id = 0;
    PortStatus status = PortStatus::IDLE;
    SessionID current_session = 0; 
    set<TimeSlot, TimeSlotLess> reservations;
};

struct Station {
    StationID id = 0;
    string name;
    Coord position{};
    ChargerType type = ChargerType::AC;

    vector<Port> ports;
    queue<CustomerID> wait_q;

    long long usage_count = 0;
    Money     revenue     = 0;
};

/// ===== Đồ thị =====
struct Edge { StationID to; double weight = 0.0; };
struct StationGraph {
    unordered_map<StationID, vector<Edge>> adj;
};

/// ===== Bảng giá =====
struct Tariff {
    Money ac_per_kWh      = 3500;
    Money dc_fast_per_kWh = 5000;
};

/// ===== Vai trò & tài khoản =====
enum class Role { Admin, Manager, Employee, User };
struct Account {
    int id = 0;
    string username;
    string password_hash;
    Role role = Role::User;
};

/// ===== Kho dữ liệu =====
struct DataStore {
    unordered_map<StationID, Station>        stations;
    unordered_map<CustomerID, Customer>      customers;
    unordered_map<SessionID, Session>        sessions;
    unordered_map<ReservationID, Reservation> reservations;

    unordered_map<int, Account>              accounts;

    unordered_map<string, CustomerID>        customer_by_phone;
    unordered_map<string, StationID>         station_by_name;

    set<pair<long long, StationID>> by_usage;
    set<pair<Money, StationID>>     by_revenue;

    StationGraph graph;
    Tariff tariff{};
};
