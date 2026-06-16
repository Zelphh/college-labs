import csv
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

rows = []
with open('resultados.csv', newline='') as f:
    reader = csv.DictReader(f)
    for row in reader:
        rows.append({k: float(v) for k, v in row.items()})

N       = [r['N']       for r in rows]
avl_add = [r['AVL_Add'] for r in rows]
avl_rem = [r['AVL_Rem'] for r in rows]
rb_add  = [r['RB_Add']  for r in rows]
rb_rem  = [r['RB_Rem']  for r in rows]
b1_add  = [r['B1_Add']  for r in rows]
b1_rem  = [r['B1_Rem']  for r in rows]
b5_add  = [r['B5_Add']  for r in rows]
b5_rem  = [r['B5_Rem']  for r in rows]
b10_add = [r['B10_Add'] for r in rows]
b10_rem = [r['B10_Rem'] for r in rows]

STYLE = dict(linewidth=1.8, marker='o', markersize=3)

# --- Adição ---
fig, ax = plt.subplots(figsize=(10, 6))
ax.plot(N, avl_add, label='AVL',        color='tab:blue',   **STYLE)
ax.plot(N, rb_add,  label='Rubro-Negra', color='tab:red',    **STYLE)
ax.plot(N, b1_add,  label='B (t=2)',    color='tab:green',  **STYLE)
ax.plot(N, b5_add,  label='B (t=5)',    color='tab:orange', **STYLE)
ax.plot(N, b10_add, label='B (t=10)',   color='tab:purple', **STYLE)
ax.set_title('Esforço Computacional — Operação de Adição', fontsize=14)
ax.set_xlabel('Tamanho do conjunto (N)', fontsize=12)
ax.set_ylabel('Operações médias por elemento', fontsize=12)
ax.legend(fontsize=11)
ax.grid(True, linestyle='--', alpha=0.5)
fig.tight_layout()
fig.savefig('grafico_adicao.png', dpi=150)
plt.close(fig)

# --- Remoção ---
fig, ax = plt.subplots(figsize=(10, 6))
ax.plot(N, avl_rem, label='AVL',        color='tab:blue',   **STYLE)
ax.plot(N, rb_rem,  label='Rubro-Negra', color='tab:red',    **STYLE)
ax.plot(N, b1_rem,  label='B (t=2)',    color='tab:green',  **STYLE)
ax.plot(N, b5_rem,  label='B (t=5)',    color='tab:orange', **STYLE)
ax.plot(N, b10_rem, label='B (t=10)',   color='tab:purple', **STYLE)
ax.set_title('Esforço Computacional — Operação de Remoção', fontsize=14)
ax.set_xlabel('Tamanho do conjunto (N)', fontsize=12)
ax.set_ylabel('Operações médias por elemento', fontsize=12)
ax.legend(fontsize=11)
ax.grid(True, linestyle='--', alpha=0.5)
fig.tight_layout()
fig.savefig('grafico_remocao.png', dpi=150)
plt.close(fig)

print("Graficos gerados: grafico_adicao.png, grafico_remocao.png")
