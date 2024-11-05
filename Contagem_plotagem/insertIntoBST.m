function node = insertIntoBST(node, value)
    if isempty(node)
        node = createNode(value);
    elseif value < node.value
        node.left = insertIntoBST(node.left, value);
    else
        node.right = insertIntoBST(node.right, value);
    end
end
