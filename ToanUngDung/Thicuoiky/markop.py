import numpy as np

# 1. Định nghĩa ma trận chuyển trạng thái P từ hình ảnh
P = np.array([
    [0.28, 0.12, 0.23, 0.37],
    [0.14, 0.36, 0.27, 0.23],
    [0.21, 0.26, 0.24, 0.29],
    [0.25, 0.31, 0.19, 0.25]
])

# 2. Vector trạng thái ban đầu (Trạng thái 1)
pi_0 = np.array([1, 0, 0, 0])

def giai_bai_toan():
    # Câu a: Tính P^3 và pi(3)
    P3 = np.linalg.matrix_power(P, 3)
    pi3 = pi_0 @ P3  # Nhân vector pi(0) với ma trận P^3
    
    print("--- CÂU A: SAU 3 GIAI ĐOẠN ---")
    print("Ma trận P^3:")
    print(np.round(P3, 3))
    print(f"Vector phân phối pi(3): {np.round(pi3, 3)}")
    print(f"=> Xác suất ở trạng thái 4: {np.round(pi3[3] * 100, 2)}%\n")

    # Câu b: Tính P^4 và pi(4)
    P4 = np.linalg.matrix_power(P, 4)
    pi4 = pi_0 @ P4  # Nhân vector pi(0) với ma trận P^4
    
    print("--- CÂU B: SAU 4 GIAI ĐOẠN ---")
    print("Ma trận P^4:")
    print(np.round(P4, 3))
    print(f"Vector phân phối pi(4): {np.round(pi4, 3)}")
    print(f"=> Xác suất ở trạng thái 4: {np.round(pi4[3] * 100, 2)}%")

if __name__ == "__main__":
    giai_bai_toan()