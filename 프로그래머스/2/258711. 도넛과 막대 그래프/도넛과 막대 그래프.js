function solution(edges) {
    let graphCnt = 0;
    let [start, donut, bar, graph8] = Array(4).fill(0);
    
    const nodes = {};
    edges.forEach(([a, b]) => {
        nodes[a] ||= {inNodes: [], outNodes: []};
        nodes[b] ||= {inNodes: [], outNodes: []};
        
        nodes[a].outNodes.push(b);
        nodes[b].inNodes.push(a);
    });
    
    for(node in nodes) {
        const {inNodes, outNodes} = nodes[node];
        
        if(inNodes.length == 0 && outNodes.length >= 2) {
            start = Number(node);
            graphCnt = outNodes.length;
        }
        else if(outNodes.length == 0) bar++;
        else if(inNodes.length >= 2 && outNodes.length >= 2) graph8++;   
    }
    
    donut = graphCnt - bar - graph8;
    
    return [start, donut, bar, graph8];
}