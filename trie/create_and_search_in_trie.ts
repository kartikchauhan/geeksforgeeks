class TrieNode {
    is_completed: boolean;
    child: Map<String, TrieNode>;
    
    constructor() {
        this.child = new Map();
        this.is_completed = false;

    }
};

// create root node
const root = new TrieNode();



function add() {
    const strings: string[] = ["abc", "abgl", "cdf", "abcd", "lmn"];

    for (let str of strings) {

        console.log('str', str);
        
        
        let currNode = root;
        
        for (let ch of str) {
            console.log('ch', ch);
            
            let nextNodeAdd = currNode.child.get(ch);
    
            console.log('\n--- nextNodeAdd', nextNodeAdd);
    
            if (nextNodeAdd === undefined) { // character is not present
    
                let newNode = new TrieNode();
    
                currNode.child.set(ch, newNode);
                currNode = newNode;
            } else {
                currNode = nextNodeAdd;
            }
    
            console.log('\n--- currNode', currNode);
    
            currNode.is_completed = true;
        }
    }
}

function search() {
    const strings: string[] = ["abc", "abgl", "cdf", "abcd", "lmn", "md"];

    const matchFound: boolean[] = [];

    for (let str of strings) {
        let currNode = root;

        let isFound = true;

        for (let ch of str) {
            console.log('ch', ch);

            let nextNodeAdd = currNode.child.get(ch);

            if (nextNodeAdd === undefined) {
                isFound = false;        
                break;
            }

            currNode = nextNodeAdd;
        }

        if (currNode.is_completed === false || isFound === false) {
            matchFound.push(false);
        } else {
            matchFound.push(true);
        }
    }

    for (let i=0; i<strings.length; i++) {
        console.log(strings[i], matchFound[i]);
    }
}

function isStringWithPrefix(prefix: String) {
    let currNode = root;

    let isFound = true;

    for (let ch of prefix) {
        console.log('ch', ch);

        let nextNodeAdd = currNode.child.get(ch);

        if (nextNodeAdd === undefined) {
            isFound = false;
            break;
        }

        currNode = nextNodeAdd;
    }

    console.log('isFound', isFound);
}

add();
search();
isStringWithPrefix("ab");
