import numpy as np

def giai_markov_tong_quat():
    # 1. Nhập kích thước ma trận
    n = int(input("Nhap kich thuoc ma tran n (vi du 3 hoac 4): "))
    
    print(f"Nhap ma tran P ({n}x{n}) tung hang mot (cach nhau boi dau cach):")
    rows = []
    for i in range(n):
        row = list(map(float, input(f"Hang {i+1}: ").split()))
        rows.append(row)
    
    P = np.array(rows)
    
    # 2. Nhập trạng thái bắt đầu (vi du: 1 cho trang thai 1)
    start_state = int(input("He thong bat dau o trang thai may (1 den n): "))
    pi_0 = np.zeros(n)
    pi_0[start_state - 1] = 1.0
    
    # 3. Nhập số bước muốn tính
    k_list = list(map(int, input("Nhap cac buoc thoi gian can tinh (vi du: 3 4): ").split()))
    
    print("\n" + "="*30)
    print("KẾT QUẢ GIẢI CHI TIẾT")
    print("="*30)

    for k in k_list:
        # Tinh P^k
        Pk = np.linalg.matrix_power(P, k)
        # Tinh pi(k) = pi(0) * P^k
        pi_k = pi_0 @ Pk
        
        print(f"\n--- TẠI BƯỚC THỨ k = {k} ---")
        print(f"Ma tran P^{k} (lam tron 3 chu so):")
        print(np.round(Pk, 3))
        print(f"Vector phan phoi xac suat pi({k}):")
        print(np.round(pi_k, 3))
        
        # Liet ke xac suat tung trang thai
        for idx, prob in enumerate(pi_k):
            print(f" + Xac suat o trang thai {idx+1}: {round(prob*100, 2)}%")

if __name__ == "__main__":
    giai_markov_tong_quat()
    