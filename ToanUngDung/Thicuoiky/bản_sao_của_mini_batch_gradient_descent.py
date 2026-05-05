import numpy as np
import matplotlib.pyplot as plt
from numpy import genfromtxt
import os  # Thêm thư viện này để xử lý đường dẫn

# --- PHẦN 1: ĐỌC VÀ XỬ LÝ DỮ LIỆU ---
# Lấy đường dẫn của thư mục chứa chính file code này
dir_path = os.path.dirname(os.path.realpath(__file__))
file_name = 'Lecture_CNTT_2020.csv'
full_path = os.path.join(dir_path, file_name)

try:
    # Đọc file bằng đường dẫn tuyệt đối
    data = genfromtxt(full_path, delimiter=',', skip_header=1)
    
    # Kiểm tra nếu data bị rỗng (NaN)
    if np.isnan(data).all():
        raise ValueError("File tim thay nhung khong co du lieu hoac sai dinh dang!")

    X = data[:, 0:3]
    y = data[:, 3:4]
    N = data.shape[0]

    # Chuẩn hóa (Normalize)
    X = (X - np.mean(X)) / (np.max(X) - np.min(X))
    X_b = np.c_[np.ones((N, 1)), X] 
    print(f"Thanh cong: Da doc duoc {N} dong du lieu tu {file_name}")

except Exception as e:
    print(f"Loi doc file: {e}")
    print(f"Hay dam bao file '{file_name}' nam tai: {dir_path}")
# --- PHẦN 2: THUẬT TOÁN MINI-BATCH ---
def mini_batch_gradient_descent(X_b, y, N):
    epoch_max = 50
    minibatch_size = 20
    learning_rate = 0.01
    thetas = np.random.randn(4, 1)
    losses = []

    for epoch in range(epoch_max):
        shuffled_indices = np.random.permutation(N)
        X_b_shuff = X_b[shuffled_indices]
        y_shuff = y[shuffled_indices]

        for i in range(0, N, minibatch_size):
            xi = X_b_shuff[i:i + minibatch_size]
            yi = y_shuff[i:i + minibatch_size]

            y_hat = xi.dot(thetas)
            loss = (y_hat - yi) ** 2
            
            # Tính gradient (d_loss)
            d_loss = 2 * (y_hat - yi) / minibatch_size
            gradients = xi.T.dot(d_loss)

            # Cập nhật
            thetas = thetas - learning_rate * gradients
            
            loss_mean = np.sum(loss) / minibatch_size
            losses.append(loss_mean)
            
    return thetas, losses

# --- PHẦN 3: MOMENTUM (HÀM 1 BIẾN) ---
def grad(x): return 2*x + 10*np.cos(x)
def cost(x): return x**2 + 10*np.sin(x)

def GD_momentum(theta_init, alpha=0.1, beta=0.9):
    theta = [theta_init]
    v_old = np.zeros_like(theta_init)
    for it in range(100): # Để 100 bước để dễ nhìn
        v_new = beta*v_old + alpha*grad(theta[-1])
        theta_new = theta[-1] - v_new
        theta.append(theta_new)
        v_old = v_new
    return (theta, it)

# --- CHƯƠNG TRÌNH CHÍNH ---
if __name__ == '__main__':
    # Chạy Mini-Batch
    if 'X_b' in locals():
        thetas, losses = mini_batch_gradient_descent(X_b, y, N)
        plt.figure(figsize=(8, 4))
        plt.plot(losses[:200], color="red", label="Loss")
        plt.title("Mini-Batch Loss Curve")
        plt.legend()
        plt.show()

    # Chạy Momentum
    (x_m, it_m) = GD_momentum(5)
    print(f"Momentum Solution x = {x_m[-1]:.4f}, cost = {cost(x_m[-1]):.4f}")