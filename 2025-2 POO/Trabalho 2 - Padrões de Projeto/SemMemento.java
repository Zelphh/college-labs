class Editor {
    private String content = "";

    public void type(String words) { this.content += " " + words; }
    
    
    public String getContent() { return this.content; }
    
    public void setContent(String content) {
        this.content = content;
    }
}

class HistorySemMemento {
    // Guarda o estado diretamente, não um objeto Memento
    private Stack<String> history = new Stack<>();

    // O History tem de "puxar" o estado do editor
    public void save(EditorSemMemento editor) {
        history.push(editor.getContent());
    }

    public void undo(EditorSemMemento editor) {
        if (!history.isEmpty()) {
            editor.setContent(history.pop()); // Usa o "setter" perigoso
        }
    }
}

// --- Demonstração ---
public void demoSemMemento() {
    EditorSemMemento editor = new EditorSemMemento();
    HistorySemMemento history = new HistorySemMemento();

    editor.type("Olá");
    history.save(editor); 
    editor.type("Mundo"); 

    
    history.undo(editor);

    
}