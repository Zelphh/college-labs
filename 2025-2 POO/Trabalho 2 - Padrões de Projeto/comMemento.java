class EditorMemento {
    private final String content;
    
    public EditorMemento(String content) { 
        this.content = content; 
    }
    
    // Apenas o Originador (Editor) pode aceder isto
    protected String getContent() {
        return content; 
    }
}

class Editor {
    private String content = "";

    public void type(String words) { this.content += " " + words; }
    public String getContent() { return this.content; }

    // Cria o Memento
    public EditorMemento save() {
        return new EditorMemento(this.content);
    }

    // Restaura a partir do Memento
    public void restore(EditorMemento memento) {
        this.content = memento.getContent();
    }
}

class History {
    private Stack<EditorMemento> history = new Stack<>();

    public void push(EditorMemento memento) { history.push(memento); }
    public EditorMemento undo() { return history.pop(); }
}


public void demoComMemento() {
    Editor editor = new Editor();
    History history = new History();

    editor.type("Olá");
    history.push(editor.save()); 
    editor.type("Mundo");        
    
    
    editor.restore(history.undo());
    
    
}